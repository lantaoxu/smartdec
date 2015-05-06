//
// SmartDec decompiler - SmartDec is a native code to C/C++ decompiler
// Copyright (C) 2015 Alexander Chernov, Katerina Troshina, Yegor Derevenets,
// Alexander Fokin, Sergey Levin, Leonid Tsvetkov
//
// This file is part of SmartDec decompiler.
//
// SmartDec decompiler is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// SmartDec decompiler is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with SmartDec decompiler.  If not, see <http://www.gnu.org/licenses/>.
//

#include "Exception.h"

namespace nc {

Exception::Exception(const QString &message) {
    *this << ExceptionMessage(message);
}

Exception::~Exception() noexcept {}

QString Exception::unicodeWhat() const noexcept {
    if (const QString *result = boost::get_error_info<ExceptionMessage>(*this)) {
        return *result;
    } else {
        return QString();
    }
}

const char *Exception::what() const noexcept {
    if (mCachedWhat.isNull()) {
        mCachedWhat = unicodeWhat().toLocal8Bit();
    }
    return mCachedWhat.data();
}

} // namespace nc

/* vim:set et sts=4 sw=4: */