package com.projectcompletion;

class B22_2122000380_ProjectCompletion{
//    1. planning, 2. designing, 3. development, 4. testing, 5. deployment
    float[] steps = {1,2,1,0.5f,0.5f};
    public float totalCompletion(){
        return steps[0] + steps[1] +steps[2] +steps[3] +steps[4];
    }
    public float remainingTime(int k){
        float sum = 0f;
        for(int i = 0; i<k; i++){
            sum+=steps[i];
        }
        return totalCompletion() - sum;
    }
}