export class MinHeap {
  private array: number[];
  private size: number;
  private maxSize: number;

  public constructor(maxSize: number) {
    this.array = new Array(maxSize);
    this.maxSize = maxSize;
    this.size = 0;
  }

  public insert(value: number) {
    if (this.size >= this.maxSize) {
      console.log("heap is full");
      return;
    }

    this.size++;
    this.array[this.size - 1] = value;
    this.heapifyUp(this.size - 1);
  }

  public extractMin() {
    if (this.size <= 0) {
      console.log("heap is empty");
      return;
    }

    let value = this.array[0];

    this.array[0] = this.array[this.size - 1];
    this.array[this.size - 1] = 0;
    this.size--;

    this.heapifyDown(0);
    return value;
  }

  private heapifyDown(index: number) {
    let smallest = index;
    let left = 2 * index + 1;
    let right = 2 * index + 2;

    if (left < this.size && this.array[left] < this.array[smallest])
      smallest = left;

    if (right < this.size && this.array[right] < this.array[smallest])
      smallest = right;

    if (smallest != index) {
      this.swap(smallest, index);
      this.heapifyDown(smallest);
    }
  }

  private heapifyUp(index: number) {
    let parent: number = ((index - 1) / 2) | 0;

    if (parent >= 0 && this.array[index] < this.array[parent]) {
      this.swap(index, parent);
      this.heapifyUp(parent);
    }
  }

  private swap(a: number, b: number) {
    let aux = this.array[a];
    this.array[a] = this.array[b];
    this.array[b] = aux;
  }

  public getArray() {
    return this.array;
  }

  public toString() {
    return `${this.array.slice(0, this.size).join(" ")} :: Size: ${this.size}`;
  }
}
