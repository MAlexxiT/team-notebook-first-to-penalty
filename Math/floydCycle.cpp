void cyclef(long long int sem){
    long long int hare = f(sem),tort=f(sem);hare = f(hare);
    //liebre avanza dos pasos, tortuga solo uno
    while(hare!=tort){
        tort = f(tort); hare = f(f(hare));
    }
    //Se detiene en el inicio del ciclo
    tort = sem;
    while(hare!=tort){
        tort = f(tort); hare = f(hare);
    }

    int len = 1;
    tort = f(sem);
    while(hare!=tort){
        tort=f(tort);
        len++;
    } 
}
