pipeline {
    agent any

    environment {
        SWC_CODE_DIR = 'Generated_SWC_Code'
        TEST_DIR     = 'Tests'
        RTE_DIR      = 'RTE'
        REPORT_DIR   = 'Reports'
    }

    stages {

        stage('Checkout') {
            steps {
                echo '--- Cloning repository ---'
                checkout scm
                bat 'mkdir Reports 2>nul || echo Reports exists'
            }
        }

        stage('MISRA-C Check') {
            steps {
                echo '--- Running MISRA-C static analysis ---'
                bat '''
                    cppcheck ^
                        --std=c99 ^
                        --xml ^
                        --xml-version=2 ^
                        %SWC_CODE_DIR%/ ^
                        2> %REPORT_DIR%/misra_report.xml
                '''
            }
            post {
                always {
                    recordIssues(
                        tools: [cppCheck(
                            pattern: 'Reports/misra_report.xml'
                        )]
                    )
                }
            }
        }

        stage('Compile Check') {
            steps {
                echo '--- Compiling generated C code ---'
                bat '''
                    gcc -Wall -Wextra ^
                        -std=c99 ^
                        -I %SWC_CODE_DIR% ^
                        -I %RTE_DIR% ^
                        %SWC_CODE_DIR%/*.c ^
                        -c
                '''
            }
        }

        stage('Unit Tests') {
            steps {
                echo '--- Running unit tests ---'
                bat '''
                    gcc ^
                        -I Unity/src ^
                        -I %SWC_CODE_DIR% ^
                        -I %RTE_DIR% ^
                        Unity/src/unity.c ^
                        %TEST_DIR%/test_BSD_Algorithm.c ^
                        %SWC_CODE_DIR%/BSD_Algorithm_swc.c ^
                        -o test_runner.exe

                    test_runner.exe
                '''
            }
            post {
                always {
                    junit allowEmptyResults: true,
                          testResults: 'Reports/test_results.xml'
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
                    publishHTML([
                        allowMissing:          false,
                        alwaysLinkToLastBuild: true,
                        keepAll:               true,
                        reportDir:             'docs/html',
                        reportFiles:           'index.html',
                        reportName:            'BSD Doxygen Docs'
                    ])
                }
            }
        }

        stage('Archive Artifacts') {
            steps {
                echo '--- Archiving build artifacts ---'
                archiveArtifacts(
                    artifacts:         'Generated_SWC_Code/**,ARXML/**,Reports/**',
                    fingerprint:       true,
                    allowEmptyArchive: true
                )
            }
        }
    }

    post {
        success {
            echo '✅ Pipeline passed'
        }
        failure {
            echo '❌ Pipeline failed'
        }
        always {
            cleanWs()
        }
    }
}