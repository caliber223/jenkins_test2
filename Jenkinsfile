#!/usr/bin/env groovy

boolean success = true
//def dockerRegistry = "registry.open-sys.org"
def dockerRegistry = "caliber223"
def imageName

properties([
    disableConcurrentBuilds()
])
sh "echo '-------------------------- step 1 -----------------------------'"
try {
    sh "echo '-------------------------- step 2 -----------------------------'"
    node('docker') {
        sh "echo '-------------------------- step 3 -----------------------------'"
        stage('Checkout') {
            sh "echo '-------------------------- step 4 -----------------------------'"
            checkout([
                sh "echo '-------------------------- step 5 -----------------------------'"
                $class: 'GitSCM',
                branches: scm.branches,
                extensions: scm.extensions + [
                    [$class: 'CleanBeforeCheckout'],
                    [$class: 'PathRestriction', includedRegions: ''],
                    //[$class: 'PathRestriction', includedRegions: '^services/.*$'],
                    [$class: 'SubmoduleOption', recursiveSubmodules: true, parentCredentials: true]
                ],
                submoduleCfg: [],
                userRemoteConfigs: [
                    //[credentialsId: 'jenkins-open-sys-with-key', url: 'git@github.com:VirtualInstruments/atr-backend.git']
                    [credentialsId: 'dockerhub-az223', url: 'git@github.com:caliber223/jenkins_test2.git']
                ]
            ])
        }
        sh "echo '-------------------------- step 6 -----------------------------'"
        imageName = "${dockerRegistry}/vz/auth"

        //docker.withRegistry("https://${dockerRegistry}/", 'docker-registry') {
        docker.withRegistry("${dockerRegistry}/", 'docker-registry') {
            sh "echo '-------------------------- step 7 -----------------------------'"
            stage('Build') {
                ansiColor('xterm') {
                    sh "./build.sh"
                }
            }
            sh "echo '-------------------------- step 8 -----------------------------'"
            stage('Push') {
                docker.image(imageName).push()
                docker.image(imageName).push('latest')
            }

        } // end 'withRegistry'
    } // end 'node'
} catch (e) {
    echo e.toString()
    sucess = false
    currentBuild.result = 'FAILURE'
} finally {
}
