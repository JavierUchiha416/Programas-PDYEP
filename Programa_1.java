public class Programa_1 implements Runnable {

    @Override
    public void run() {
        synchronized (objeto) {
            
            for (int i = 0; i < 10000; i++) {
            
                cont++;

            }

        }

    }

    public static void main(String[] args) throws Exception {
        Thread[] hilos = new Thread[2];
        
        for (int i = 0; i < hilos.length; i++) {
            Runnable runnable = new Programa_1();
            hilos[i] = new Thread(runnable);
            hilos[i].start();
        }
        for (int i = 0; i < hilos.length; i++) {
            hilos[i].join();
        }


        
        System.out.println(cont);

    }

    private static int cont = 0;
    /* El sinchornized debe de llegar algun objeto, cualquiera */
    private static Object objeto = new Object();

}
