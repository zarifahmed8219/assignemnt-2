

import java.script.Scanner;
import javax.script.ScriptEngine;
import javax.script.ScriptEngineManager;
import javax.script.ScriptException;

public class Assignment2 {

    public static void main(String[] args) throws ScriptException {

        Scanner sc = new Scanner(System.in);


        int m = Integer.parseInt(sc.nextLine());
        String var[] = new String[m];
        for (int i = 0; i < m; i++) {
            var[i] = sc.nextLine();
        }

        int n = Integer.parseInt(sc.nextLine());
        String equ[] = new String[n];
        for (int i = 0; i < n; i++) {
            equ[i] = sc.nextLine();
        }

        try {
            for (int i = 0; i < n; i++) {
                equ[i] = equ[i].replaceAll(" ", "");
                for (int j = 0; j < m; j++) {
                    var[j] = var[j].replaceAll(" ", "");
                    String[] x = var[j].split("=");
                    equ[i] = equ[i].replaceAll(x[0], x[1]);
                }
                ScriptEngineManager mgr = new ScriptEngineManager();
                ScriptEngine engine = mgr.getEngineByName("JavaScript");
                System.out.println(engine.eval(equ[i]));
            }
        }catch(ScriptException e){
            System.out.println("Compilation Error");
        }
    }
}





