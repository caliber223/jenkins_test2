#!/usr/bin/env groovy

boolean success = true
def dockerRegistry = "registry.open-sys.org"
def baseImageName
def imageName
baseImageName = "${dockerRegistry}/test/auth"
imageName = "${baseImageName}"
echo "------------------------ step 1 -----------------------"
properties([
    disableConcurrentBuilds()
])

 pipeline {
    agent {
        label ('master')
    }
    options {
        timestamps()
    }
    stages {
        stage('Docker login') {
            steps {
                echo "====================     docker login     ======================="
                withCredentials([usernamePassword(credentialsId: 'jenkins-azot3-with-key', usernameVariable: 'USERNAME', passwordVariable: 'PASSWORD')]) {
                    sh "docker login -u $USERNAME -p $PASSWORD"
                }
            }
        }


        /*docker.withRegistry("https://${dockerRegistry}/", 'docker-registry') {

            stage('Build') {
                ansiColor('xterm') {
                    sh "./build.sh"
                }
            }

            stage('Push') {
                docker.image(imageName).push()
                docker.image(imageName).push('latest')
            }

        } // end 'withRegistry'*/
    } // end stages

}

echo "------------------------ step end -----------------------"
