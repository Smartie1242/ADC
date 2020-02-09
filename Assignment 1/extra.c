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

	for (int i = 0; i < n; i++) {

		int *signal, l;
		int size = 1;
		signal = malloc(sizeof(int));
		signal[0] = 0;
		scanf("%d", &l);

		for (int j = 0; j < l; j++) {
			int a, b, layer;
			//scanf("%d %d %d", &a, &b, &layer);
			scanf("[%d,%d)@%d ", &a, &b, &layer);
			if (b > size) {
				signal = realloc(signal, b * sizeof(int));
				while(size < b) {
					signal[size] = 0;
					size++;
				}
				size = b;
			}
			while (a < b) {
				if (layer > signal[a]) {
					signal[a] = layer;
				}
				a++;
			}
		}

		printf("%d\n", size);
		for (int j = 0; j < size; j++) {
			printf("%d ", signal[j]);
		}
		printf("\n");
		free(signal);
	}
	return 0;
}
