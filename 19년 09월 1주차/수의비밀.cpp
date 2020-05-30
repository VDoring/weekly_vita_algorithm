#include <iostream>
using namespace std;

int main() {
	int num;
	scanf("%d", &num);

	while (num % 2) {
		if (num == 1) printf("Yes");
		else printf("No");
		return 0;
	}

	return 0;
}