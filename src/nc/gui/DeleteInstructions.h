/* * SmartDec decompiler - SmartDec is a native code to C/C++ decompiler
 * Copyright (C) 2015 Alexander Chernov, Katerina Troshina, Yegor Derevenets,
 * Alexander Fokin, Sergey Levin, Leonid Tsvetkov
 *
 * This file is part of SmartDec decompiler.
 *
 * SmartDec decompiler is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * SmartDec decompiler is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with SmartDec decompiler.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <nc/config.h>

#include <memory>
#include <vector>

#include "Command.h"

namespace nc {

namespace core {
    namespace arch {
        class Instruction;
    }
}

namespace gui {

class Project;

/**
 * Command for decompiling the project.
 */
class DeleteInstructions: public Command {
    Q_OBJECT

    /** Project. */
    Project *project_;

    /** Instructions to be removed. */
    std::vector<std::shared_ptr<const core::arch::Instruction>> instructions_;

    public:

    /**
     * Constructor.
     *
     * \param project Valid pointer to a project.
     * \param instructions Instructions to delete.
     */
    DeleteInstructions(Project *project, const std::vector<const core::arch::Instruction *> &instructions);

    void work() override;
};

}} // namespace nc::gui

/* vim:set et sts=4 sw=4: */