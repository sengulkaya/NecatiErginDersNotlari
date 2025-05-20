
class Car {
public:
	virtual ~Car() = default;
	virtual Car* clone() = 0;
	virtual void start() = 0;
	virtual void run() = 0;
	virtual void stop() = 0;
	virtual std::ostream& print(std::ostream&) const = 0;
	friend std::ostream& operator<<(std::ostream& os, const Car& c)
	{
		return c.print(os);
	}
	
};

class Mercedes : public Car {
public:
	std::ostream& print(std::ostream& os) const override {
		return os << "I am a Mercedes";
	}

	Mercedes* clone() override
	{
		return new Mercedes(*this);
	}

	void start() override { std::cout << "Mercedes::start()\n"; }
	void run() override { std::cout << "Mercedes::run()\n"; }
	void stop()override { std::cout << "Mercedes::stop ()\n"; }
};

class Renault : public Car {
public:
	std::ostream& print(std::ostream& os) const override {
		return os << "I am a Renault";
	}

	Renault* clone()override {
		return new Renault(*this);
	}

	void start() override { std::cout << "Renault::start()\n"; }
	void run() override { std::cout << "Renault::run()\n"; }
	void stop() override { std::cout << "Renault::stop ()\n"; }
};

class Volvo : public Car {
public:
	virtual std::ostream& print(std::ostream& os) const override {
		return os << "I am a Volvo";
	}

	Volvo* clone()override {
		return new Volvo(*this);
	}

	void start() override { std::cout << "Volvo::start()\n"; }
	void run() override { std::cout << "Volvo::run()\n"; }
	void stop()override { std::cout << "Volvo::stop ()\n"; }

	void open_sunroof()
	{
		std::cout << "volvo sunroof opened!\n";
	}

};

class VolvoXC90 : public Volvo {
public:
	 std::ostream& print(std::ostream& os) const override {
		return os << "I am a VolvoXC90";
	}

	VolvoXC90* clone()override {
		return new VolvoXC90(*this);
	}

	void start() override { std::cout << "VolvoXC90::start()\n"; }
	void run() override { std::cout << "VolvoXC90::run()\n"; }
	void stop()override { std::cout << "VolvoXC90::stop ()\n"; }


	void open_sunroof()
	{
		std::cout << "volvoXC90 sunroof opened!\n";
	}
};




Car* create_random_car()
{
	static std::mt19937 eng;
	static std::uniform_int_distribution dist{ 0,3 };

	switch (dist(eng))
	{
	case 0:  return new Volvo;
	case 1:  return new Renault;
	case 2:  return new Mercedes;
	case 3:  return new VolvoXC90;
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