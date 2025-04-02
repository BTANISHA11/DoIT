class Solution {
public:
tm parseDate(const string& dateStr){
    tm date={};
    stringstream ss(dateStr);
    //parse date in format 
    ss>>get_time(&date,"%Y-%m-%d");
    return date;
}
    int daysBetweenDates(string date1, string date2) {
        //parse input date string
        tm d1=parseDate(date1);
        tm d2=parseDate(date2);
        time_t t1=mktime(&d1);
        time_t t2=mktime(&d2);
        double diffInSecond=difftime(t1,t2);
        return abs(diffInSecond)/(60*60*24);
    }
};