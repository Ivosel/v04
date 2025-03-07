#pragma once
#include <string>
#include <memory>

namespace vsite::oop::v4
{
	class animal {
	public:
		virtual std::string species() const = 0;
		virtual uint32_t legs() const = 0;
		virtual ~animal() = 0;
	};

	class insect : public animal {
	public:
		uint32_t legs() const override;
	};

	class spider : public animal {
	public:
		uint32_t legs() const override;
	};

	class bird : public animal {
	public:
		uint32_t legs() const override;
	};

	class cockroach : public insect {
	public:
		std::string species() const override;
	};

	class tarantula : public spider {
	public:
		std::string species() const override;
	};

	class sparrow : public bird {
	public:
		std::string species() const override;
	};

	class leg_counter {
		uint32_t nr_legs;
	public:
		leg_counter();
		uint32_t legs() const;
		std::string add_animal(const animal* a);

	};

	std::unique_ptr<animal> animal_factory(uint32_t id);
}