
/*                sorting functions                     */

// Tri a Bulle
void tri_bulle(int* tab, int taille){
    int i, j, swap;
    for(i=taille-1;i>0;i--){
        for(j=1;j<=i;j++){
            if(tab[j-1]>tab[j]){
                swap = tab[j];
                tab[j] = tab[j-1];
                tab[j-1] = swap;
            }
        }
    }
}
// Tri par insertion
void tri_insertion(int* tab, int taille){
    int i, j, swap;
    for(i=1;i<taille;i++){
        swap = tab[i];
        j = i;
        while(j > 0 && tab[j-1] > swap){
            tab[j] = tab[j-1];
            j--;
        }
        tab[j] = swap;
    }
}
// Tri par selection
void tri_selection(int* tab, int taille){
    int i, j, min, swap;
    for(i=0;i<taille;i++){
        min = i;
        for(j=i+1;j<=taille;j++){
            if(tab[j]<tab[min]) min =j;
        }
        swap = tab[i];
        tab[i] = tab[min];
        tab[min] = swap;
    }
}
// Tri rapide
void tri_rapide(int* tab, int taille);
// Tri fusion

void merge(int *tab, int first, int mid, int last){
    int f = first, m = mid+1, i = 0, k;
    int *temp, taille;
    taille = last - first +1;
    temp = malloc(sizeof(int)*taille);
    while((f<=mid) &&(m<=last)){
        if(tab[f] > tab[m]) temp[i]= tab[m++];
        else temp[i]= tab[f++];
        i++;
    }
    if(f>mid){
        for(k=m;k<=last;k++){
            temp[i++] = tab[k];
        }
    }
    else{
        for(k=f;k<=mid;k++){
            temp[i++] = tab[k];
        }
    }
    for(k=first;k<=last;k++){
        tab[k] = temp[k-first];
    }
    free(temp);
}
void tri_fusion(int* tab, int first, int last){
    if(first < last){
            int mid = (first+last)/2;
            tri_fusion(tab, first, mid);
            tri_fusion(tab, mid+1, last);
            merge(tab, first, mid, last);
    }
}
// Tri tas
void heapify(int *heap,int i,int size){
    int left_child = i*2-1, right_child = i*2, max = --i;
    if((left_child < size) &&(heap[left_child] > heap[i])){
        max = left_child;
    }
    if((right_child < size) && (heap[right_child] > heap[max])){
        max = right_child;
    }
    if(max != i){
        int temp;
        temp = heap[i];
        heap[i] = heap[max];
        heap[max] = temp;
        heapify(heap, max+1,size);
    }

}

void build_heap(int * heap,int size){
    int i;
    for(i=size/2;i>0;i--){
        heapify(heap, i,size);
    }
}

void tri_tas(int* heap, int size){
    int temp,i,j;
    build_heap(heap, size);
    for(i=size;i>1;i--){
        temp = heap[i-1];
        heap[i-1] = heap[0];
        heap[0] = temp;
        heapify(heap,1,i-1);
    }
}
