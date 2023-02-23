#ifndef EARTH_H
#define EARTH_H


class Earth {
public:
	
	int x_ = 0;

	static Earth& GetInstance() {
		// gets instantiated the first time
		static Earth instance; // guaranteed to be destroyed

		return instance;
	}

    int get_population() { return population_; };

    void IncreasePopulation() { population_ += 1; };

	// Delete the methods we don't want
	Earth(Earth const&) = delete; // copy constructor // Earth e; Earth e2(e)
	void operator=(Earth const&) = delete; // assignment operator //Earth e; Earth e2 = e;

 private:
 	Earth();  // private constructor

    int population_;

	friend bool operator==(const Earth &lhs, const Earth& rhs){
		if ((lhs.population_ == rhs.population_) && (lhs.x_ == rhs.x_)){
			return true;
		}
		return false;
	}
  
};  // class Earth

#endif  // EARTH_H

