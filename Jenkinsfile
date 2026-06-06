pipeline {    
    agent any    
    environment {        
        PROJECT_NAME    = 'BSD_AUTOSAR_ECU'        
        SWC_CODE_DIR    = 'Generated_SWC_Code'        
        TEST_DIR        = 'Tests'        
        UNITY_DIR       = 'Unity/src'        
        REPORT_DIR      = 'Reports'    
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
                // Pointed explicitly to \source and added \includes path
                bat 'cppcheck --std=c99 --xml --xml-version=2 -I %SWC_CODE_DIR%\\includes %SWC_CODE_DIR%\\source 2> %REPORT_DIR%\\misra_report.xml || exit 0'            
            }            
            post {                
                always {                    
                    recordIssues(tools: [cppCheck(pattern: 'Reports/misra_report.xml')])                
                }            
            }        
        }        
       stage('Compile Check') {
    steps {
        echo '--- Compiling generated C code ---'
        bat '''
            dir /s /b Generated_SWC_Code\\*.c
        '''
        bat '''
            for /r Generated_SWC_Code %%f in (*.c) do (
                echo Compiling: %%f
                gcc -Wall -std=c99 ^
                    -I Generated_SWC_Code ^
                    -I RTE ^
                    "%%f" -c
            )
        '''
    }
}
        stage('Unit Tests') {            
            steps {                
                echo '--- Running unit tests ---'                
                // Updated to target BSD_System.c instead of the non-existent Algorithm file
                bat 'gcc -I %UNITY_DIR% -I %SWC_CODE_DIR%\\includes %UNITY_DIR%\\unity.c %TEST_DIR%\\test_BSD_System.c %SWC_CODE_DIR%\\source\\BSD_System.c -o test_runner.exe'
                bat 'test_runner.exe --junit-output %REPORT_DIR%\\test_results.xml'            
            }            
            post {                
                always { junit 'Reports/test_results.xml' }            
            }        
        }        
        stage('Generate Docs') {            
            steps {                
                echo '--- Generating Doxygen documentation ---'                
                bat 'doxygen Doxyfile'            
            }            
            post {                
                success {                    
                    publishHTML(target: [                        
                        allowMissing: false,                        
                        alwaysLinkToLastBuild: true,                        
                        keepAll: true,                        
                        reportDir: 'docs/html',                        
                        reportFiles: 'index.html',                        
                        reportName: 'BSD Doxygen Docs'                    
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
                    Reports/** ''', fingerprint: true            
            }        
        }    
    }    
    post {        
        success { echo '✅ Pipeline passed — all checks green' }        
        failure { echo '❌ Pipeline failed — check stage logs' }        
        always { cleanWs() }    
    }
}