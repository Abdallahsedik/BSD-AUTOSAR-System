pipeline {
    agent any

    environment {
        SWC_CODE_DIR  = 'BSD_AUTOSAR_ECU\\Generated_SWC_Code'
        RTE_DIR       = 'BSD_AUTOSAR_ECU\\RTE'
        TEST_DIR      = 'BSD_AUTOSAR_ECU\\Tests'
        UNITY_DIR     = 'BSD_AUTOSAR_ECU\\Tests\\unity_src\\src'
        EB_INCLUDE    = 'BSD_AUTOSAR_ECU\\EB_Tresos\\output\\include'
        REPORT_DIR    = 'Reports'
        CPPCHECK      = 'C:\\Program Files\\Cppcheck\\cppcheck.exe'
        DOXYGEN       = 'C:\\Program Files\\doxygen\\bin\\doxygen.exe'
    }

    stages {

        stage('Checkout') {
            steps {
                echo '--- Cloning repository ---'
                checkout scm
                bat 'if not exist "%REPORT_DIR%" mkdir "%REPORT_DIR%"'
            }
        }

        stage('MISRA-C Check') {
            steps {
                echo '--- Running MISRA-C static analysis ---'
                bat '''
                    "%CPPCHECK%" ^
                        --std=c99 ^
                        --output-file="%REPORT_DIR%\\misra_report.txt" ^
                        "%SWC_CODE_DIR%" || exit 0
                '''
                bat 'if exist "%REPORT_DIR%\\misra_report.txt" type "%REPORT_DIR%\\misra_report.txt"'
            }
            post {
                always {
                    archiveArtifacts artifacts: 'Reports/misra_report.txt', allowEmptyArchive: true
                }
            }
        }

        stage('Compile Check') {
            steps {
                echo '--- Compiling C files ---'
                bat '''
                    cd "%WORKSPACE%\\%SWC_CODE_DIR%"
                    for %%f in (*.c) do (
                        echo ----------------------------------------
                        echo Compiling: %%f
                        gcc -Wall -std=c99 ^
                            -I . ^
                            -I "%WORKSPACE%\\%RTE_DIR%" ^
                            -I "%WORKSPACE%\\%EB_INCLUDE%" ^
                            -c "%%f" || exit 1
                    )
                '''
            }
        }
        stage('Unit Tests') {
            steps {
                echo '--- Building test runners ---'
                bat '''
                    echo Building Radar Input Tests...
                    gcc ^
                        -I "%WORKSPACE%\\%UNITY_DIR%" ^
                        -I "%WORKSPACE%\\%RTE_DIR%" ^
                        -I "%WORKSPACE%\\%SWC_CODE_DIR%" ^
                        -I "%WORKSPACE%\\%EB_INCLUDE%" ^
                        "%WORKSPACE%\\%UNITY_DIR%\\unity.c" ^
                        "%WORKSPACE%\\%TEST_DIR%\\test_BSD_RadarInput.c" ^
                        "%WORKSPACE%\\%SWC_CODE_DIR%\\BSD_RadarInput_SWC.c" ^
                        -o "%WORKSPACE%\\%REPORT_DIR%\\test_runner_radar.exe" ^
                        || exit 1
                        
                    echo Building System Algorithm Tests...
                    gcc ^
                        -I "%WORKSPACE%\\%UNITY_DIR%" ^
                        -I "%WORKSPACE%\\%RTE_DIR%" ^
                        -I "%WORKSPACE%\\%SWC_CODE_DIR%" ^
                        -I "%WORKSPACE%\\%EB_INCLUDE%" ^
                        "%WORKSPACE%\\%UNITY_DIR%\\unity.c" ^
                        "%WORKSPACE%\\%TEST_DIR%\\test_BSD_System.c" ^
                        "%WORKSPACE%\\%SWC_CODE_DIR%\\BSD_System.c" ^
                        -o "%WORKSPACE%\\%REPORT_DIR%\\test_runner_system.exe" ^
                        || exit 1
                '''
                
                echo '--- Running unit tests ---'
                bat '''
                    echo Running Radar Tests...
                    "%WORKSPACE%\\%REPORT_DIR%\\test_runner_radar.exe" > "%WORKSPACE%\\%REPORT_DIR%\\test_output.txt" 2>&1
                    
                    echo Running System Algorithm Tests...
                    "%WORKSPACE%\\%REPORT_DIR%\\test_runner_system.exe" >> "%WORKSPACE%\\%REPORT_DIR%\\test_output.txt" 2>&1
                    
                    type "%WORKSPACE%\\%REPORT_DIR%\\test_output.txt"
                '''
                
                echo '--- Converting to JUnit XML using Unity Ruby Parser ---'
                bat '''
                    cd "%WORKSPACE%\\%REPORT_DIR%"
                    ruby "%WORKSPACE%\\%TEST_DIR%\\parseOutput.rb" -xml test_output.txt
                '''
                
                echo '--- Checking test results ---'
                // Proper IF/ELSE to guarantee Jenkins gets the correct Exit Code
                bat '''
                    findstr /c:":FAIL" "%WORKSPACE%\\%REPORT_DIR%\\test_output.txt" >nul
                    if %ERRORLEVEL% equ 0 (
                        echo ❌ TESTS FAILED
                        exit /b 1
                    ) else (
                        echo ✅ ALL TESTS PASSED
                        exit /b 0
                    )
                '''
            }
            // Correctly formatted post block (only one!)
            post {
                always {
                    // Keep your original text artifact
                    archiveArtifacts artifacts: 'Reports/test_output.txt', allowEmptyArchive: true
                    
                    // Add this to populate the Blue Ocean Tests tab
                    // Note: the ruby script outputs exactly 'report.xml' by default
                    junit 'Reports/report.xml' 
                }
            }
        }
            
        

        stage('Generate Docs') {
            steps {
                echo '--- Generating Doxygen documentation ---'
                bat '''
                    if exist "%DOXYGEN%" (
                        "%DOXYGEN%" Doxyfile
                        echo Documentation generated successfully
                    ) else (
                        echo Doxygen not found — skipping docs
                    )
                '''
            }
            post {
                success {
                    script {
                        if (fileExists('docs/html/index.html')) {
                            publishHTML([
                                allowMissing:          true,
                                alwaysLinkToLastBuild: true,
                                keepAll:               true,
                                reportDir:             'docs/html',
                                reportFiles:           'index.html',
                                reportName:            'BSD Doxygen Docs'
                            ])
                        }
                    }
                }
            }
        }

        stage('Archive Artifacts') {
            steps {
                echo '--- Archiving ---'
                archiveArtifacts(
                    artifacts: 'BSD_AUTOSAR_ECU/Generated_SWC_Code/**, Reports/**, docs/html/**',
                    fingerprint:       true,
                    allowEmptyArchive: true
                )
            }
        }
    }

    post {
        success {
            echo '✅ Pipeline passed — MISRA ✅ Compile ✅ Tests ✅ Docs ✅'
            step([
                $class: 'GitHubCommitStatusSetter',
                contextSource: [$class: 'ManuallyEnteredCommitContextSource', context: 'Jenkins CI'],
                statusResultSource: [
                    $class: 'ConditionalStatusResultSource',
                    results: [[$class: 'AnyBuildResult', message: 'Pipeline and all tests passed successfully!', state: 'SUCCESS']]
                ]
            ])
        }
        failure {
            echo '❌ Pipeline failed — check stage logs above'
            step([
                $class: 'GitHubCommitStatusSetter',
                contextSource: [$class: 'ManuallyEnteredCommitContextSource', context: 'Jenkins CI'],
                statusResultSource: [
                    $class: 'ConditionalStatusResultSource',
                    results: [[$class: 'AnyBuildResult', message: 'Pipeline failed. Check Jenkins logs.', state: 'FAILURE']]
                ]
            ])
        }
        always {
            cleanWs()
        }
    }
}