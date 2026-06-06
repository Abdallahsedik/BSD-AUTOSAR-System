pipeline {
    agent any

    environment {
        SWC_CODE_DIR = 'Generated_SWC_Code'
        RTE_DIR      = 'RTE'
        REPORT_DIR   = 'Reports'
    }

    stages {

        stage('Checkout') {
            steps {
                echo '--- Cloning repository ---'
                checkout scm
                bat 'if not exist "Reports" mkdir "Reports"'
            }
        }

        stage('MISRA-C Check') {
            steps {
                echo '--- Running MISRA-C static analysis ---'
                bat '''
                    cppcheck ^
                        --std=c99 ^
                        --output-file=Reports\\misra_report.txt ^
                        %SWC_CODE_DIR%\\
                '''
                bat 'type Reports\\misra_report.txt'
            }
            post {
                always {
                    archiveArtifacts artifacts: 'Reports/misra_report.txt',
                                     allowEmptyArchive: true
                }
            }
        }

        stage('Compile Check') {
            steps {
                echo '--- Listing C files ---'
                bat 'dir /s /b %SWC_CODE_DIR%\\*.c'
                echo '--- Compiling ---'
                bat '''
                    for /r %SWC_CODE_DIR% %%f in (*.c) do (
                        echo Compiling: %%f
                        gcc -Wall -std=c99 ^
                            -I %SWC_CODE_DIR% ^
                            -I %RTE_DIR% ^
                            "%%f" -c ^
                            || exit /b 1
                    )
                '''
            }
        }

        stage('Archive Artifacts') {
            steps {
                echo '--- Archiving ---'
                archiveArtifacts(
                    artifacts:         '%SWC_CODE_DIR%/**,ARXML/**,Reports/**',
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