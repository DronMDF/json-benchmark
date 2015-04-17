
#pragma once
#include <chrono>
#include <iostream>
#include <stdexcept>
#include <string>

template<typename T>
class Skeleton {
public:
	virtual std::string name() const = 0;
	virtual T prepare(size_t size) const = 0;
	virtual std::string jsonify(const T &data) const = 0;
	virtual T parse(const std::string &s) const = 0;
	virtual bool isEqual(const T &a, const T &b) const = 0;

	void run(size_t size) const
	{
		std::cout << name() << std::endl;
		const auto data = prepare(size);
		const auto start_jsonify = std::chrono::high_resolution_clock::now();
		const auto json = jsonify(data);
		const auto stop_jsonify = std::chrono::high_resolution_clock::now();
		std::cout << "jsonify: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop_jsonify - start_jsonify).count() << "ms" << std::endl;
		const auto start_parse = std::chrono::high_resolution_clock::now();
		const auto result = parse(json);
		const auto stop_parse = std::chrono::high_resolution_clock::now();
		std::cout << "parse: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop_parse - start_parse).count() << "ms" << std::endl;
		if (!isEqual(data, result)) {
			throw std::runtime_error("Wrong alghorythm");
		}
	}
};


