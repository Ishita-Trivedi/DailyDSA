class FoodRatings {
private:
unordered_map<string,string>foodToCuisine;//food->cuisine
unordered_map<string,int>foodToRating;
unordered_map<string,set<pair<int,string>>>cuisinesToRatingFood;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<cuisines.size();i++){
            foodToRating[foods[i]]=ratings[i];
            foodToCuisine[foods[i]]=cuisines[i];
     cuisinesToRatingFood[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
      auto cuisine=foodToCuisine[food];
      int oldRating=foodToRating[food];
      cuisinesToRatingFood[cuisine].erase({-oldRating,food});
      cuisinesToRatingFood[cuisine].insert({-newRating,food});
      foodToRating[food]=newRating;
    }
    
    string highestRated(string cuisine) {
        return (*cuisinesToRatingFood[cuisine].begin()).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */