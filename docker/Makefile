#TODO (NNN): add possibility to build project in two modes:
#1. with statically linked libraries (as it doing now)
#2. with dynamically linked libraries

include tasks.mk

#use Bash instead of SH
export SHELL := /bin/bash

all:

.PHONY: help
help: ## Display this help message
	@echo "Please use \`make <target>\` where <target> is one of:"
	@cat $(MAKEFILE_LIST) | grep -e "^[a-zA-Z_\-\.]*: *.*## *" | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

