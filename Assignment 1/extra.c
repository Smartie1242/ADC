/*file:    extra.c							   */
/*author:  Joel Kiers (email: j.k.kiers@student.rug.nl)*/
/*partner: Marten Bosma (email: m.bosma.21@student.rug.nl)*/
/*date:    9 Feb, 2020								   */
/*version: 1.0 										   */
/*Description: This program transforms a level representation	into a signal.   */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int main(int argc, char*argv[]) {
	int n;
	scanf("%d", &n);
	printf("%d\n", n);

	for (int i = 0; i < n; i++) { // One loop for every signal

		int *signal, l; // Initialize the array {0}
		int size = 1;
		signal = malloc(sizeof(int));
		signal[0] = 0;

		scanf("%d", &l);
		getchar();

		for (int j = 0; j < l; j++) { // Loops for every layer provided each signal
			int a, b, layer;
			scanf("[%d,%d)@%d ", &a, &b, &layer);
			if (b > size) { // Makes the array bigger if needed
				signal = realloc(signal, b * sizeof(int));
				while(size < b) { // Fills unaccounted spaces in array with 0's
					signal[size] = 0;
					size++;
				}
				size = b;
			}

			while (a < b) { // Fills array with layer values for every layer
				if (layer > signal[a]) {
					signal[a] = layer;
				}
				a++;
			}
		}

		printf("%d\n", size);
		for (int j = 0; j < size; j++) { // Print the signal (array)
			printf("%d ", signal[j]);
		}
		printf("\n");
		free(signal);
	}
	return 0;
}
