.PHONY: test

test: 
	$(CC) -g -Wall -o test easy_config.c easy_config_test.c
clean:
	rm test
