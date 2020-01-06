# clear the contents of the results files
echo -n ""> finalResults1.txt
echo -n ""> finalResults2.txt

#run the pipe line version of printing out the top ten names and save results into finalResults1.txt
cat /data/raw/census/dist.all.last |head -10>> finalResults1.txt

#run the code with the popen version of finding the top ten names and save the results into finalResults.txt
./finalProj >> finalResults2.txt

diff finalResults1.txt finalResult2.txt
   
