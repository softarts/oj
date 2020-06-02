package com.zhourui.other;

import com.zhourui.codech.BaseSolution;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ForkJoinPool;
import java.util.concurrent.RecursiveAction;

class Product {
    public String name;
    public double price;
}
class ProductListGenerator {
    List<Product> generate(int size) {
        List<Product> ret = new ArrayList();
        for (int i=0;i<size;i++) {
            Product product = new Product();
            product.name = "Product"+i;
            product.price = 10.0;
            ret.add(product);
        }
        return ret;
    }
}

// RecursiveAction
class Task extends RecursiveAction {
    private static final long serialVersionUUID = 1L;
    private List<Product> products;
    private int first;
    private int last;
    private double increament;
    public Task(List<Product> products,int first,int last,double increament) {
        this.products = products;
        this.first = first;
        this.last = last;
        this.increament = increament;
    }
    @Override
    protected void compute() {
        if (last-first < 10) {
            updatePrices();
        } else {
            int middle = (first+last)/2;
            System.out.printf("pending tasks:%s\n",getQueuedTaskCount());
            Task t1 = new Task(products, first,middle+1,increament);
            Task t2 = new Task(products, middle+1,last,increament);
            invokeAll(t1,t2);
        }
    }

    void updatePrices() {
        for (int i=first;i<last;i++) {
            Product product = products.get(i);
            product.price = product.price *(1+increament);
        }
    }
}

public class TestForkJoin extends BaseSolution {
    @Override
    public boolean test() {
        ProductListGenerator generator = new ProductListGenerator();
        List<Product> products = generator.generate(10000);
        Task task = new Task(products,0,products.size(),0.20);
        ForkJoinPool pool = new ForkJoinPool();
        pool.execute(task);

        do {
            System.out.printf("Main thread count %s\n",pool.getActiveThreadCount());
            System.out.printf("Main thread steal %s\n",pool.getStealCount());
            System.out.printf("Main parallelism  %s\n",pool.getParallelism());
            try {
                Thread.sleep(1000);
            } catch (Exception e) {
                e.printStackTrace();
            }
        } while (!task.isDone());
        return true;
    }
}
