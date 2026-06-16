CC          = cc
CFLAGS      = -g3 -Wextra -Werror -Wall

# IMPORTANTE: Garanta que nenhum desses arquivos tenha uma função main()
C_FILES     =	../philosophers.c \
				../init_simulation.c \
				../free_destroy.c \
				../ft_atol.c

UTIL_FILES  = utils/test_log.c \
			  utils/capture_stdout.c

LIBS        =  # -ldl -glfw -pthread -lm
HEADERS     = -I. -I$(TEST_DIR) -I..

			  # Tests section
			  TEST_DIR    = ./
			  TEST_SRCS   = $(TEST_DIR)/test-ft_atol.c \
							$(TEST_DIR)/test-parse_args.c \
							$(TEST_DIR)/test-init_sim.c

TEST_BINS   = $(TEST_SRCS:.c=.out)
REPORT_LOG  = test_report.log

# Alvo principal de teste
test:
	@rm -f $(REPORT_LOG)
	@echo "TEST REPORT - $(shell date)" > $(REPORT_LOG)
	@echo "------------------------------------------" >> $(REPORT_LOG)
	@# Run binaries ignoring errors for the jog to keep running
	-@$(MAKE) run_test_bins --no-print-directory
	@# Final summary processing
	@TOTAL=$$(grep -c "Case:" $(REPORT_LOG)); \
	PASSED=$=$$(grep -c "\[PASS\]" $(REPORT_LOG)); \
	FAILS=$$(grep -c "\[FAIL\]" $(REPORT_LOG)); \
	ERRORS=$$(grep -c "\[ERROR\]" $(REPORT_LOG)); \
	echo "" >> $(REPORT_LOG); \
	echo "==========================================" >> $(REPORT_LOG); \
	echo "📊 Summary:" >> $(REPORT_LOG); \
	echo "  Total cases:  $$TOTAL" >> $(REPORT_LOG); \
	echo "  ✅ Pass:      $$PASSED" >> $(REPORT_LOG); \
	echo "  ❌ Fail:      $$FAILS" >> $(REPORT_LOG); \
	echo "  ⚠️ Errors:     $$ERRORS" >> $(REPORT_LOG); \
	echo "==========================================" >> $(REPORT_LOG); \
	cat $(REPORT_LOG); \
	if grep -qE "\[FAIL\]|\[ERROR\]" $(REPORT_LOG); then \
		echo "\033[0;31m\n[!] Test suite failed.\033[0m"; \
		exit 1; \
	else \
		echo "\033[0;32m\n[+] Test suite passed successfully.\033[0m"; \
		exit 0; \
	fi

single:
	@echo "Compiling individual test file for: $(T)"
	$(CC) $(CFLAGS) $(C_FILES) $(UTIL_FILES) test-$(T).c $(HEADERS) -o unit_test.out

run_test_bins: $(TEST_BINS)

# Regra de compilação e execução por arquivo
$(TEST_DIR)/%.out: $(TEST_DIR)/%.c
	@# Tries to compile. If fail, log it to log file.
	@$(CC) $(CFLAGS) $(C_FILES) $(UTIL_FILES) $< $(HEADERS) -o $@ >> $(REPORT_LOG) 2>&1 || \
		(echo "\nFile: $<" >> $(REPORT_LOG) && \
		 echo "      [ERROR] Compilation failed" >> $(REPORT_LOG) && exit 0)
	@# If binary was created, runs it and cleans it
	@if [ -f $@ ]; then \
		echo "\nFile: $<" >> $(REPORT_LOG); \
		./$@ || true; \
		rm -f $@; \
	fi

clean:
	rm -f *.out

fclean: clean
	@rm -rf $(REPORT_LOG)

.PHONY: test run_test_bins clean fclean