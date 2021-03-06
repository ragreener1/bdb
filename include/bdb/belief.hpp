/* BDB, Behaviour-Derived Beliefs.
 * Copyright (C) 2022 Robert Greener.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef BDB_BEHAVIOUR_H
#define BDB_BEHAVIOUR_H

#include "bdb/named.hpp"
#include "bdb/uuidd.hpp"
#include <boost/uuid/uuid.hpp>
#include <string>

namespace BDB {
/**
 * @brief The base type of a belief.
 */
class BaseBelief : public Named, public UUIDd {
public:
  /**
   * @brief Construct a new BaseBelief object.
   *
   * This randomly generates a UUIDv4.
   *
   * @param name The name of the belief.
   */
  BaseBelief(const std::string name);

  /**
   * @brief Construct a new BaseBelief object.
   *
   * @param name The name of the belief.
   * @param uuid The UUID of the belief.
   */
  BaseBelief(const std::string name, const boost::uuids::uuid uuid);

  /**
   * @brief Destroy the BaseBelief object.
   */
  virtual ~BaseBelief() {}

  /**
   * @brief Get the Relationship object.
   *
   * @param other The other belief.
   * @return const double The relationship.
   */
  [[nodiscard("Accessor")]] virtual const double
  getRelationship(const BaseBelief *other) const = 0;

  /**
   * @brief Set the Relationship object
   *
   * @param other The other belief.
   * @param relationship The new relationship.
   */
  virtual void setRelationship(const BaseBelief *other,
                               const double relationship) = 0;
};
} // namespace BDB

#endif // BDB_BEHAVIOUR_H