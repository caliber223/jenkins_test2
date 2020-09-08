#!/bin/bash

###################
# Main script logic
###################

# STAGE 1. Build Auth-service docker image
build_final_image() {
  local file="Dockerfile"
  local msg="\n===> [STAGE 1] Auth service image: Building."
  echo -e "${msg}"
  docker build --tag=caliber223/vz/auth:latest --file=${file} .
}

main() {

  build_final_image

}

main "$@"
