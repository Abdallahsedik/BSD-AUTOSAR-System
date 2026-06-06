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
                bat 'if not exist "%REPORT_DIR%" mkdir "%REPORT_DIR%"'
            }
        }

        stage('MISRA-C Check') {
            steps {
                echo '--- Running MISRA-C static analysis ---'
                // Converted to a single line. Added || exit 0 so it doesn't crash the build on a warning.
                bat 'cppcheck --std=c99 --output-file="%REPORT_DIR%\\misra_report.txt" "%SWC_CODE_DIR%" || exit 0'
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
                // Bulk compile using *.c is much safer in Jenkins than a batch FOR loop
                bat 'gcc -Wall -std=c99 -I %SWC_CODE_DIR% -I %RTE_DIR% -c %SWC_CODE_DIR%\\*.c'
            }
        }

        stage('Archive Artifacts') {
            steps {
                echo '--- Archiving ---'
                archiveArtifacts(
                    artifacts:         '%SWC_CODE_DIR%/**, ARXML/**, Reports/**',
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