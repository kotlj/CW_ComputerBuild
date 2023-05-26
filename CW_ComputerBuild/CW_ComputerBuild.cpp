
#include <iostream>
#include <string>

class Computer
{
private:
	std::string proccesor;
	std::string memory;
	std::string hardDrive;
public:
	void setProccesor(std::string _proccesor)
	{
		this->proccesor = _proccesor;
	}
	std::string getProccesor() const
	{
		return this->proccesor;
	}

	void setMem(std::string _mem)
	{
		this->memory = _mem;
	}
	std::string getMem() const
	{
		return this->memory;
	}

	void setHardDrive(std::string _hardDrive)
	{
		this->hardDrive = _hardDrive;
	}
	std::string getHardDrive() const
	{
		return this->hardDrive;
	}
};

class ComputerBuilder abstract
{
protected:
	Computer computer;
public:
	Computer getComp()
	{
		return computer;
	}
	virtual void BuildProcces() abstract;
	virtual void BuildMem() abstract;
	virtual void BuildHardDrive() abstract;
};

class ChipComputerBuilder : public ComputerBuilder
{
public:
	void BuildProcces() override
	{
		computer.setProccesor("Pentium 3");
	}
	void BuildMem() override
	{
		computer.setMem("DDR3-1333");
	}
	void BuildHardDrive() override
	{
		computer.setHardDrive("HDD SATA 320GB Seagate 5900rpm 16GB");
	}
};

class HightComputerBuilder : public ComputerBuilder
{
	void BuildProcces() override
	{
		computer.setProccesor("Intel core i7 7000");
	}
	void BuildMem() override
	{
		computer.setMem("Dell EMC 64GB DDR4 LRDIMM 2666MHz 1.2V Load Reduced");
	}
	void BuildHardDrive() override
	{
		computer.setHardDrive("Transcend StoreJet 25M3C 2TB");
	}
};

class Director
{
public:
	void buildComputer(ComputerBuilder* _builder)
	{
		_builder->BuildProcces();
		_builder->BuildMem();
		_builder->BuildHardDrive();

		std::cout << "\nProccesor: " << _builder->getComp().getProccesor() <<
			"\nMemory: " << _builder->getComp().getMem() <<
			"\nHardDrive: " << _builder->getComp().getHardDrive() << '\n';
	}
};

int main()
{
	Director director;
	ComputerBuilder* builder = new ChipComputerBuilder;
	director.buildComputer(builder);
	delete builder;
	builder = new HightComputerBuilder;
	director.buildComputer(builder);
	delete builder;
}
