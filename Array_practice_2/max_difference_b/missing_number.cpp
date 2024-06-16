int missingNumber=-1;
        for(int curNum=0;curNum<=n;curNum++){
            bool found=false;
            for(int num:nums){ //iterate over all 
                if(num==curNum){
                    found=true;
                    break;
                }
            }
            if(!found){
                missingNumber=curNum;
                break;
            }
        }
        return missingNumber;