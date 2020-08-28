include .env.dev
export

COMPOSE_CMD_DB = docker-compose -p repeat_check --file compose-files/local.yml

local.up: local.pull ### Update images and start all services.
	@$(COMPOSE_CMD_DB) up -d
	@echo
	@$(COMPOSE_CMD_DB) ps
	@echo "<==============================================>"

local.down: ### Stop services.
	@$(COMPOSE_CMD_DB) down

local.pull:
	@$(COMPOSE_CMD_DB) pull || true

local.ps: ### Show services status.
	@$(COMPOSE_CMD_DB) ps





