#include <stdlib.h>
#include <stdio.h>
#include "easy_config.h"

int manTest(const char* category, char* key, char* value, EConfig* econfig, void* user_param) {
	printf("Found param %s :)\nValue is: %s\n", key, value);

	return 0;
}

int main(int argc, char** argv) {

	const char* file = NULL;

	EConfig* config = econfig_init(file, NULL);

	unsigned catGeneral = econfig_addCategory(config, "general");
	unsigned catInput = econfig_addCategory(config, "input");

	econfig_addParam(config, catGeneral, "test", manTest);
	econfig_addParam(config, catInput, "test", manTest);
	econfig_addParam(config, catInput, "host", manTest);

	int out = econfig_parse(config);

	econfig_free(config);

	switch(out) {
		case EC_CANNOT_OPEN_FILE:
			printf("Cannot open file.\n");
			break;
		case EC_CAT_NOT_FOUND:
			printf("Category not found.\n");
			break;
		case EC_PARSING_ERROR:
			printf("Cannot parse file.\n");
			break;
		case EC_KEY_NOT_FOUND:
			printf("Key not found.\n");
			break;
	}

	return out * (-1);
}
