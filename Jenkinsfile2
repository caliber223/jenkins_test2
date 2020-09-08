#!groovy
// Build repeat_check
properties([disableConcurrentBuilds()])

pipeline {
    agent {
        label 'master'
    }
    options {
        buildDiscarder(logRotator(numToKeepStr: '10', artifactNumToKeepStr: '10'))
        timestamps()
    }
    stages {
        stage("Build Docker image") {
            steps {
                echo "===================== start building image ======================"
                sh './build.sh'
            }
        }
    }
}
