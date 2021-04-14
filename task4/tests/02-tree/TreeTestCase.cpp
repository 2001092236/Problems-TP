//
// Created by akhtyamovpavel on 5/1/20.
//


#include "TreeTestCase.h"
#include "Tree.h"

namespace bfs = boost::filesystem;

TEST_F(TreeTestCase, GetTree) {
    ASSERT_ANY_THROW(GetTree("bla-bla-bla", true));
    boost::system::error_code ec;

    boost::filesystem::create_directories("dir/subdir", ec);
    std::ofstream ofs("dir/file.txt");
    GetTree("./dir", true);

    GetTree("./dir", false);
    ASSERT_ANY_THROW(GetTree("dir/file.txt", true));
    boost::filesystem::remove_all("dir", ec);
}

TEST_F(TreeTestCase, FilterEmptyNodes) {
    boost::system::error_code ec;

    boost::filesystem::create_directories("dir/subdir", ec);
    std::ofstream ofs("dir/file.txt");

    ASSERT_FALSE(GetTree("./dir", false) == GetTree("./dir", true));
    boost::filesystem::remove_all("dir", ec);
}
