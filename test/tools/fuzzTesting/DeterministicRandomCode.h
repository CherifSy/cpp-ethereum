/*
	This file is part of cpp-ethereum.

	cpp-ethereum is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	cpp-ethereum is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with cpp-ethereum.  If not, see <http://www.gnu.org/licenses/>.
*/
/** @file DeterministicRandomCode.h
 * @date 2017
 */

#pragma once
#include <string>
#include <test/tools/fuzzTesting/BoostRandomCode.h>

namespace dev
{
namespace test
{

class DeterministicRandomCode: public BoostRandomCode
{
public:
	DeterministicRandomCode(std::string const& _seed)
	{
		setHash(_seed);
	}

protected:
	void refreshSeed() {
		gen.seed(seed);
	}
	void setHash(std::string const& _seed)
	{
		seed = 0;
		for (size_t i=0; i < _seed.length(); i++)
			seed += _seed.at(i)*i;
	}
	unsigned seed;
};


}
}
