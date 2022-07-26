class compare{
    public:
    bool operator()(const pair<int,string>&p1,const pair<int,string>&p2)const{
        if(p1.first==p2.first)
            return p1.second<p2.second;
        return p1.first>p2.first;
    }
};

class FoodRatings {
    unordered_map<string,set<pair<int,string>,compare> > cuisine_rating;
    unordered_map<string,string> food_cuisine;
    unordered_map<string,int> food_rating;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0;i<n;i++)
        {
            cuisine_rating[cuisines[i]].insert({ratings[i],foods[i]});
            food_cuisine[foods[i]] = cuisines[i];
            food_rating[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        auto& cuisine = food_cuisine.find(food)->second;
        cuisine_rating[cuisine].erase({food_rating[food],food});
        cuisine_rating[cuisine].insert({newRating,food});
        food_rating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return cuisine_rating[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */