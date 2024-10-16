#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "UniquePtr.h"

struct Entity {
    int id = -1;
};

struct CustomDeleterEntity {
    int id = 0;
    ~CustomDeleterEntity() {
        std::cout << "Custom deleter called for id: " << id << "\n";
    }
};

TEST_CASE("UniquePtr basic functionality") {
    UniquePtr<Entity> entityPtr(new Entity{10});
    CHECK(entityPtr);
    CHECK(entityPtr->id == 10);
    CHECK((*entityPtr).id == 10);
}

TEST_CASE("UniquePtr release and reset") {
    UniquePtr<Entity> entityPtr(new Entity{20});
    Entity* rawPtr = entityPtr.release();
    CHECK(rawPtr->id == 20);
    CHECK(entityPtr.get() == nullptr);
    delete rawPtr;  // Manual deletion after release

    entityPtr.reset(new Entity{30});
    CHECK(entityPtr);
    CHECK(entityPtr->id == 30);
}

TEST_CASE("UniquePtr custom deleter") {
    bool customDeleterCalled = false;
    {
        UniquePtr<Entity> entityPtr(new Entity{40}, [&](Entity* e) {
            customDeleterCalled = true;
            delete e;
        });
        CHECK(entityPtr->id == 40);
    }
    CHECK(customDeleterCalled);
}

TEST_CASE("UniquePtr move semantics") {
    UniquePtr<Entity> entityPtr(new Entity{50});
    UniquePtr<Entity> movedPtr = std::move(entityPtr);
    CHECK(!entityPtr);  // Original pointer should be null
    CHECK(movedPtr->id == 50);

    UniquePtr<Entity> secondMovedPtr;
    secondMovedPtr = std::move(movedPtr);
    CHECK(!movedPtr);
    CHECK(secondMovedPtr->id == 50);
}

TEST_CASE("UniquePtr swap functionality") {
    UniquePtr<Entity> ptr1(new Entity{60});
    UniquePtr<Entity> ptr2(new Entity{70});
    
    ptr1.swap(ptr2);
    CHECK(ptr1->id == 70);
    CHECK(ptr2->id == 60);
}
