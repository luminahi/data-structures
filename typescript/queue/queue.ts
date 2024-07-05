type QueueNode<T> = {
    value: T;
    right: QueueNode<T> | null;
    left: QueueNode<T> | null;
};

export class Queue<T> {
    private head: QueueNode<T> | null;
    private tail: QueueNode<T> | null;
    private size: number;

    public constructor() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    private createNode(value: T): QueueNode<T> {
        return { value, left: null, right: null };
    }

    public enqueue(value: T): number {
        let node = this.createNode(value);
        if (this.size === 0) {
            this.head = node;
            this.tail = node;
        } else {
            this.tail!.left = node;
            node.right = this.tail;
            this.tail = node;
        }

        return this.size++;
    }

    public dequeue(): number {
        if (this.size === 0) return this.size;
        if (this.size === 1) {
            this.head = null;
            this.tail = null;
        } else {
            this.head!.left!.right = null;
            this.head = this.head!.left;
        }

        return this.size--;
    }

    public getSize() {
        return this.size;
    }

    public print() {
        let iterator = this.tail;
        while (iterator) {
            process.stdout.write(`[${iterator.value}] `);
            iterator = iterator.right;
        }
        process.stdout.write("\n");
    }

    public toString(): string {
        return `[TAIL: ${this.tail?.value}] <==> [HEAD: ${this.head?.value}]\nSize: ${this.size}`;
    }
}
