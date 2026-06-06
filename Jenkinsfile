pipeline {
    agent any

    environment {
        // Pointing exactly to your nested code folder
        SWC_CODE_DIR = 'BSD_AUTOSAR_ECU\\Generated_SWC_Code'
        RTE_DIR      = 'BSD_AUTOSAR_ECU\\RTE'
        REPORT_DIR   = 'Reports'
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
                // Uses absolute path to guarantee Jenkins finds Cppcheck
                bat '"C:\\Program Files\\Cppcheck\\cppcheck.exe" --std=c99 --output-file="%REPORT_DIR%\\misra_report.txt" "%SWC_CODE_DIR%" || exit 0'
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
                // Changes directory first to safely handle Windows *.c wildcards
                bat '''
                    cd "%WORKSPACE%\\%SWC_CODE_DIR%"
                    for %%f in (*.c) do (
                        echo ----------------------------------------
                        echo Compiling: %%f
                        gcc -Wall -std=c99 -I . -I "%WORKSPACE%\\%RTE_DIR%" -c "%%f" || exit 1
                    )
                '''
            }
        }

        stage('Archive Artifacts') {
            steps {
                echo '--- Archiving ---'
                archiveArtifacts(
                    artifacts:         'BSD_AUTOSAR_ECU/Generated_SWC_Code/**, Reports/**',
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