#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<errno.h>

#define HIGH_INTENSTY_GREEN "\e[0;92m"
#define HIGH_INTENSTY_RED "\x1b[31m"
#define HIGH_INTENSTY_PURPLE "\e[0;95m"
#define GREEN "\x1b[32m"
#define RED "\e[0;91m"
#define COLOR_RESET "\x1b[0m" 

void main(void){
	char input[20];
		
	printf("Do you really want to proceed with the installation of sublime text 4?");
	printf("(");
	printf(GREEN "Y" COLOR_RESET);
	printf(HIGH_INTENSTY_GREEN "es" COLOR_RESET);
	printf(",");
	printf(RED "N" COLOR_RESET);
	printf(HIGH_INTENSTY_RED "o" COLOR_RESET);
	printf("):");

	int x = 1;

	while(x == 1){	
		scanf("%s", input);
	
		if((*input == 'y' || *input == 'Y') || (input == "Yes" || input == "yes")){
			printf(HIGH_INTENSTY_PURPLE "installation started\n" COLOR_RESET);
		
			system("wget https://download.sublimetext.com/sublime_text_build_4107_x64.tar.xz");
			system("tar -xvf sublime*.xz");
		
			DIR* dir = opendir("/opt");
		
			if(dir){
    			closedir(dir);
			
				system("rm -r sublime*.xz && sudo mv sublime_text /opt && sudo cp -r sublime_text.desktop /usr/share/applications");
				system("sudo ln -s /opt/sublime_text/sublime_text /usr/local/bin");

				printf(HIGH_INTENSTY_GREEN "Installation completed successfully! ;D\n" COLOR_RESET);

				break;
			}else if(ENOENT == errno){
				system("mkdir /opt");

				break;
			}else{
				printf(RED "error\n");

				break;
			}
		}else if((*input == 'n' || *input == 'N') || (input == "No" || input == "no")){
			printf("You canceled\n");

			break;
		}else{
			printf(RED "Invalid value! :/\n" COLOR_RESET);

			break;
		}
	}	
}