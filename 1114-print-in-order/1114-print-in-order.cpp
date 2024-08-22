class Foo {
public:
    int turn;
    mutex m;
    condition_variable cv;
    Foo() {
        turn=0;
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        turn=2;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
       unique_lock<mutex>lock(m);
       while(turn!=2){
       cv.wait(lock);//we pass the lock to be waited in the lock function
       }
       turn=3;
        printSecond();
        cv.notify_all();
    }

    void third(function<void()> printThird) {
               unique_lock<mutex>lock(m);
       while(turn!=3){
       cv.wait(lock);//we pass the lock to be waited in the lock function
       }
        printThird();
    }
};