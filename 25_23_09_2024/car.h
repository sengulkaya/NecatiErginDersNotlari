
class Car {
public:
	virtual ~Car() = default;
	virtual void start() { std::cout << "Car::start()\n"; }
	virtual void run() { std::cout << "Car::run()\n"; }
	virtual void stop() { std::cout << "Car::stop ()\n"; }
	virtual std::ostream& print(std::ostream&) const = 0;
	friend std::ostream& operator<<(std::ostream& os, const Car& c)
	{
		return c.print(os);
	}
};

class Volvo : public Car {
public:
	void start() override { std::cout << "Volvo::start()\n"; }
	void run() override { std::cout << "Volvo::run()\n"; }
	void stop()override { std::cout << "Volvo::stop ()\n"; }
	std::ostream& print(std::ostream& os) const override {
		return os << "I am a Volvo";
	}
};

class Renault : public Car {
public:
	void start() override { std::cout << "Renault::start()\n"; }
	void run() override { std::cout << "Renault::run()\n"; }
	void stop() override { std::cout << "Renault::stop ()\n"; }
	std::ostream& print(std::ostream& os) const override {
		return os << "I am a Renault";
	}
};

class Mercedes : public Car {
public:
	void start() override { std::cout << "Mercedes::start()\n"; }
	void run() override { std::cout << "Mercedes::run()\n"; }
	void stop()override { std::cout << "Mercedes::stop ()\n"; }
	std::ostream& print(std::ostream& os) const override {
		return os << "I am a Mercedes";
	}
};
Car* create_random_car()
{
	static std::mt19937 eng;
	static std::uniform_int_distribution dist{ 0,2 };

	switch (dist(eng))
	{
	case 0:  return new Volvo;
	case 1:  return new Renault;
	case 2:  return new Mercedes;
	default: return nullptr;
		break;
	}
}

void car_game(Car& c)

{
	c.start();
	c.run();
	c.stop();
}