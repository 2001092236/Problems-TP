//
// Created by akhtyamovpavel on 5/1/20.
//


#include "TreeTestCase.h"
#include "Tree.h"

namespace bfs = boost::filesystem;

TEST_F(TreeTestCase, GetTree) {

    ASSERT_ANY_THROW(GetTree("bla bla bla", true));
    boost::system::error_code ec;

	
    string ph = bfs::temp_directory_path().string() + "/" + bfs::unique_path().string()
    boost::filesystem::create_directories(ph, ec);


    GetTree(ph, true);

    GetTree(ph, false);
    ASSERT_ANY_THROW(GetTree(ph + "/file.txt", true));
    boost::filesystem::remove_all(ph, ec);
}

TEST_F(TreeTestCase, FilterEmptyNodes) {
    boost::system::error_code ec;

    string ph = bfs::temp_directory_path().string() + "/" + bfs::unique_path().string()
    boost::filesystem::create_directories(ph + "/subdir", ec);
    std::ofstream ofs(ph + "/file.txt");

    ASSERT_FALSE(GetTree(ph, false) == GetTree(ph, true));
    ///FilterEmptyNodes(GetTree("./dir", false), ".");
    FilterEmptyNodes(GetTree(ph, false), ph);
    ///FilterEmptyNodes(GetTree("./dir/file.txt", false), "./dir/file.txt");
    boost::filesystem::remove_all(ph, ec);
}
