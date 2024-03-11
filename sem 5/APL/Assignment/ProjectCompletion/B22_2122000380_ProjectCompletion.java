class B22_2122000380_ProjectCompletion{
    float steps[] = {1,2,1,0.5f,0.5f};
    public float totalCompletetion(){
        return steps[0] + steps[1] +steps[2] +steps[3] +steps[4];
    }
    public float remainingTime(int k){
        float sum = 0f;
        for(int i = 0; i<k; i++){
            sum+=steps[i];
        }
        return totalCompletetion() - sum;
    }
    public static void main(String[] args) {
        B22_2122000380_ProjectCompletion obj = new B22_2122000380_ProjectCompletion();
        System.out.println("Total : " + obj.totalCompletetion() + " weeks");
        System.out.println("Time remaining after 4 phases : " + obj.remainingTime(4) + " weeks");
    }
}