for((i=0;i<=1000;++i)) do
   #./philo 199 800 200 200 3 | tail -1 ; sleep .2
   ./philo 199 800 200 200 3 | grep eating | wc -l
done
