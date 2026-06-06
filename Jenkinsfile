pipeline {
    agent any

    environment {
        PROJECT_NAME    = 'BSD_AUTOSAR_ECU'
        SWC_CODE_DIR    = 'Generated_SWC_Code'
        TEST_DIR        = 'Tests'
        RTE_DIR         = 'RTE'
        UNITY_DIR       = 'Unity/src'
        REPORT_DIR      = 'Reports'
    }

    stages {

        stage('Checkout') {
            steps {
                echo '--- Cloning repository ---'
                checkout scm
                // Windows equivalent of mkdir -p
                bat 'if not exist "%REPORT_DIR%" mkdir "%REPORT_DIR%"'
            }
        }

        stage('MISRA-C Check') {
            steps {
                echo '--- Running MISRA-C static analysis ---'
                // Formatted as a single line to avoid Windows multi-line breaks
                bat 'cppcheck --addon=misra --std=c99 --xml --xml-version=2 "%SWC_CODE_DIR%" 2> "%REPORT_DIR%\\misra_report.xml"'
            }
            post {
                always {
                    recordIssues(
                        tools: [cppCheck(pattern: 'Reports/misra_report.xml')]
                    )
                }
            }
        }

        stage('Compile Check') {
            steps {
                echo '--- Compiling generated C code ---'
                // Changing directory first to safely use the *.c wildcard
                bat '''
                    cd "%WORKSPACE%\\%SWC_CODE_DIR%"
                    gcc -Wall -Wextra -std=c99 -I . -I "%WORKSPACE%\\%RTE_DIR%" -c *.c
                '''
            }
        }

        stage('Unit Tests') {
            steps {
                echo '--- Running unit tests ---'
                // Compiling to an .exe, then running the .exe
                bat '''
                    gcc -I "%UNITY_DIR%" -I "%SWC_CODE_DIR%" -I "%RTE_DIR%" "%UNITY_DIR%\\unity.c" "%TEST_DIR%\\test_BSD_Algorithm.c" "%SWC_CODE_DIR%\\BSD_Algorithm_swc.c" -o test_runner.exe
                    test_runner.exe --junit-output "%REPORT_DIR%\\test_results.xml"
                '''
            }
            post {
                always {
                    junit 'Reports/test_results.xml'
                }
            }
        }

        stage('Generate Docs') {
            steps {
                echo '--- Generating Doxygen documentation ---'
                bat 'doxygen Doxyfile'
            }
            post {
                success {
                    // Added target: [] which is required in newer Jenkins versions
                    publishHTML(target: [
                        allowMissing: false,
                        alwaysLinkToLastBuild: true,
                        keepAll: true,
                        reportDir:    'docs/html',
                        reportFiles:  'index.html',
                        reportName:   'BSD Doxygen Docs'
                    ])
                }
            }
        }

        stage('Archive Artifacts') {
            steps {
                echo '--- Archiving build artifacts ---'
                archiveArtifacts artifacts: '''
                    Generated_SWC_Code/**/*.c,
                    Generated_SWC_Code/**/*.h,
                    ARXML/**/*.arxml,
                    Reports/**
                ''', fingerprint: true
            }
        }
    }

    post {
        success {
            echo '✅ Pipeline passed — all checks green'
        }
        failure {
            echo '❌ Pipeline failed — check stage logs'
        }
        always {
            cleanWs()
        }
    }
}