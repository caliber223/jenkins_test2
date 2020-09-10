#!/usr/bin/env groovy

boolean success = true
def dockerRegistry = "registry.open-sys.org"
//def dockerRegistry = "caliber223"
def imageName

properties([
    disableConcurrentBuilds()
])

try {
    node('docker') {
        stage('Checkout') {
            checkout([
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
                    //[credentialsId: 'dockerhub-az223', url: 'git@github.com:caliber223/jenkins_test2.git']
                    [credentialsId: 'dockerhub-az223', url: 'git@github.com:caliber223/jenkins_test2.git']
                ]
            ])
        }

        baseImageName = "${dockerRegistry}/test/auth"
        imageName = "${baseImageName}"

        docker.withRegistry("https://${dockerRegistry}/", 'docker-registry') {
        //docker.withRegistry("${dockerRegistry}/", 'docker-registry') {

            stage('Build') {
                ansiColor('xterm') {
                    sh "./build.sh"
                }
            }

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
