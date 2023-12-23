#include "Soup/JsonFloat.hpp"

#include "Soup/string.hpp"
#include "Soup/Writer.hpp"

namespace soup
{
	JsonFloat::JsonFloat(double value) noexcept
		: JsonNode(JSON_FLOAT), value(value)
	{
	}

	std::string JsonFloat::encode() const
	{
		return string::fdecimal(value);
	}

	bool JsonFloat::binaryEncode(Writer& w) const
	{
		uint8_t b = JSON_FLOAT;
		uint64_t val;
		*reinterpret_cast<double*>(&val) = value;
		return w.u8(b)
			&& w.u64(val)
			;
	}
}
