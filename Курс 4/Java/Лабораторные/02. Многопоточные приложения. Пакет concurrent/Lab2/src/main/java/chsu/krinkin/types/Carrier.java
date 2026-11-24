package chsu.krinkin.types;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Semaphore;

public class Carrier {

    List<Operator> operators = new ArrayList<>();
    Semaphore semaphore;

    void setOperatorsCount(int count) {
        if (operators.size() < count)
            for (int i = 0; i < count-operators.size(); i++) {
                //operators.add(new Operator());
            }
        if (operators.size() > count)
            for (int i = 0; i < count; i++) {

            }
    }

    Object[] getOperators() {
        return operators.toArray();
    }

    void requestCall() {

    }
}
