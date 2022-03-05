/** Interface file for key encryption
 *
 *  \file imgs/ipcv/key_encryption/KeyEncryption.h
 *  \author Carl Salvaggio, Ph.D. (salvaggio@cis.rit.edu)
 *  \co-author Myles Stelling (mcs2868@g.rit.edu)
 *  \date created 10 January 2020
 *  \date edited 5 March 2022
 */

#pragma once

#include <string>

namespace ipcv {

/** Perform key encryption of provide string
 *
 *  \param[in]   key   encryption key
 *  \param[in]   str   string to encrypt
 *
 *  \return   the encrypted string
 */
std::string Encrypt(const std::string& key, const std::string& str);

/** Perform key decryption of provided string
 *
 *  \param[in]   key   encryption key
 *  \param[in]   str   string to decrypt
 *
 *  \return   the decrypted string
 */
std::string Decrypt(const std::string& key, const std::string& encrypted_str);
}
