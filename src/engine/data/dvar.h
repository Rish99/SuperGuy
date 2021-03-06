/* ============================================================================
 * Name        : dvar.h
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : FreeBSD
 * Description : Class for the dvars
 * ============================================================================ */

#ifndef DVAR_H_
#define DVAR_H_

#include <stdint.h>
#include <string>
#include <boost/variant.hpp>

typedef enum dvar_flag {
	DVAR_FLAG_NONE = 0x00,
	DVAR_FLAG_ARCHIVED = 0x01,
	DVAR_FLAG_WRITEPROTECTED = 0x02,
	DVAR_FLAG_CHEAT = 0x04,
	DVAR_FLAG_READONLY = 0x08,
	DVAR_FLAG_USERCREATED = 0x10
} dvar_flag_t;

inline dvar_flag_t operator|(dvar_flag_t a, dvar_flag_t b) {
	return static_cast<dvar_flag_t>(static_cast<int>(a) | static_cast<int>(b));
}

typedef boost::variant<int64_t, std::string, double, bool> dvar_value_t;

class dvar {
public:
	/*! \brief Makes a new dvar with the type of a integer.
	 \param name The name of the dvar.
	 \param desc The description of the dvar.
	 \param flags The flags for the dvar.
	 \param Int The default value for the dvar.
	 */
	dvar(std::string name, std::string desc, dvar_flag_t flags, int64_t Int);
	/*! \brief Makes a new dvar with the type of a string.
	 \param name The name of the dvar.
	 \param desc The description of the dvar.
	 \param flags The flags for the dvar.
	 \param String The default value for the dvar.
	 */
	dvar(std::string name, std::string desc, dvar_flag_t flags,
			std::string String);
	/*! \brief Makes a new dvar with the type of a double.
	 \param name The name of the dvar.
	 \param desc The description of the dvar.
	 \param flags The flags for the dvar.
	 \param Double The default value for the dvar.
	 */
	dvar(std::string name, std::string desc, dvar_flag_t flags, double Double);
	/*! \brief Makes a new dvar with the type of a boolean.
	 \param name The name of the dvar.
	 \param desc The description of the dvar.
	 \param flags The flags for the dvar.
	 \param Bool The default value for the dvar.
	 */
	dvar(std::string name, std::string desc, dvar_flag_t flags, bool Bool);
	~dvar();

	/*! \brief Returns the name of the dvar.
	 \return The name of the dvar.
	 */
	std::string getName();
	/*! \brief Returns the description of the dvar.
	 \return The description of the dvar.
	 */
	std::string getDesc();
	/*! \brief Returns the flags of the dvar.
	 \return The flags of the dvar.
	 */
	dvar_flag_t getFlags();
	/*! \brief Returns the default value of the dvar.
	 \return The default value of the dvar.
	 */
	dvar_value_t getDefValue();
	/*! \brief Returns the value of the dvar.
	 \return The value of the dvar.
	 */
	dvar_value_t getValue();

	/*! \brief Sets the description of the dvar.
	 \param desc The description.
	 */
	void setDesc(std::string desc);
	/*! \brief Sets the flags of the dvar.
	 \param flag The flags.
	 */
	void setFlags(dvar_flag_t flag);
	/*! \brief Sets the default value of the dvar.
	 \param defValue The default value.
	 */
	void setDefValue(dvar_value_t defValue);
	/*! \brief Sets the value of the dvar and returns DVAR_FLAG_NONE if it succeeded else it return the flag that stopped it.
	 \param value The value.
	 \return The flag that stopped it or DVAR_FLAG_NONE if it succeeded.
	 */
	dvar_flag_t setValue(dvar_value_t value);
private:
	std::string name;
	std::string desc;
	dvar_flag_t flags;
	dvar_value_t defValue;
	dvar_value_t value;
};

#endif /* DVAR_H_ */
