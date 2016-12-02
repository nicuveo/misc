const char* DATA = "const char* DATA = %c%s%c;%cint main() { printf(DATA,34,DATA,34,10,10); return 0; }%c";
int main() { printf(DATA,34,DATA,34,10,10); return 0; }
