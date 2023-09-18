#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void format(char* fname, int ds, int kstr);
int noformat(char* fname);
void selectfile(char* fname);
void Clean(char* fname);
void save(char* fname, char* p, int ks);
void printsave(char* fname, char* p, int ks);
int strlong(char* fname, int ds);

#endif
