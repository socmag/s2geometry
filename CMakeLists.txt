cmake_minimum_required(VERSION 2.8.12)
project(s2-geometry)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include(CheckCXXCompilerFlag)
include(FindPackageHandleStandardArgs)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/third_party/cmake")

find_package(OpenSSL REQUIRED)
# pthreads isn't used directly, but this is still required for std::thread.
find_package(Threads REQUIRED)


# Avoid "Policy CMP0042 is not set" warning on macOS.
if (APPLE)
    set(CMAKE_MACOSX_RPATH TRUE)
endif()

add_definitions(-Wno-deprecated-declarations -std=c++11)

# If OpenSSL is installed in a non-standard location, configure with
# something like:
# OPENSSL_ROOT_DIR=/usr/local/opt/openssl cmake ..
include_directories(
    ${GFLAGS_INCLUDE_DIRS} ${GLOG_INCLUDE_DIRS} ${OPENSSL_INCLUDE_DIR}
    ${PYTHON_INCLUDE_DIRS})
include_directories(src)

add_library(s2 STATIC
            src/s2/base/stringprintf.cc
            src/s2/base/strtoint.cc
            src/s2/id_set_lexicon.cc
            src/s2/mutable_s2shape_index.cc
            src/s2/r2rect.cc
            src/s2/s1angle.cc
            src/s2/s1chord_angle.cc
            src/s2/s1interval.cc
            src/s2/s2boolean_operation.cc
            src/s2/s2builder.cc
            src/s2/s2builder_graph.cc
            src/s2/s2builderutil_closed_set_normalizer.cc
            src/s2/s2builderutil_find_polygon_degeneracies.cc
            src/s2/s2builderutil_s2point_vector_layer.cc
            src/s2/s2builderutil_s2polygon_layer.cc
            src/s2/s2builderutil_s2polyline_layer.cc
            src/s2/s2builderutil_s2polyline_vector_layer.cc
            src/s2/s2builderutil_snap_functions.cc
            src/s2/s2builderutil_testing.cc
            src/s2/s2cap.cc
            src/s2/s2cell.cc
            src/s2/s2cell_id.cc
            src/s2/s2cell_union.cc
            src/s2/s2centroids.cc
            src/s2/s2closest_edge_query.cc
            src/s2/s2closest_point_query.cc
            src/s2/s2contains_vertex_query.cc
            src/s2/s2convex_hull_query.cc
            src/s2/s2coords.cc
            src/s2/s2crossing_edge_query.cc
            src/s2/s2debug.cc
            src/s2/s2earth.cc
            src/s2/s2edge_clipping.cc
            src/s2/s2edge_crosser.cc
            src/s2/s2edge_crossings.cc
            src/s2/s2edge_distances.cc
            src/s2/s2edge_tessellator.cc
            src/s2/s2error.cc
            src/s2/s2furthest_edge_query.cc
            src/s2/s2latlng.cc
            src/s2/s2latlng_rect.cc
            src/s2/s2latlng_rect_bounder.cc
            src/s2/s2lax_loop_shape.cc
            src/s2/s2lax_polygon_shape.cc
            src/s2/s2lax_polyline_shape.cc
            src/s2/s2loop.cc
            src/s2/s2measures.cc
            src/s2/s2metrics.cc
            src/s2/s2max_distance_targets.cc
            src/s2/s2min_distance_targets.cc
            src/s2/s2padded_cell.cc
            src/s2/s2point_compression.cc
            src/s2/s2point_region.cc
            src/s2/s2pointutil.cc
            src/s2/s2polygon.cc
            src/s2/s2polyline.cc
            src/s2/s2polyline_simplifier.cc
            src/s2/s2predicates.cc
            src/s2/s2projections.cc
            src/s2/s2r2rect.cc
            src/s2/s2region.cc
            src/s2/s2region_term_indexer.cc
            src/s2/s2region_coverer.cc
            src/s2/s2region_intersection.cc
            src/s2/s2region_union.cc
            src/s2/s2shape_index.cc
            src/s2/s2shape_index_buffered_region.cc
            src/s2/s2shapeutil_build_polygon_boundaries.cc
            src/s2/s2shapeutil_contains_brute_force.cc
            src/s2/s2shapeutil_edge_iterator.cc
            src/s2/s2shapeutil_get_reference_point.cc
            src/s2/s2shapeutil_range_iterator.cc
            src/s2/s2shapeutil_visit_crossing_edge_pairs.cc
            src/s2/s2text_format.cc
            src/s2/s2wedge_relations.cc
            src/s2/strings/serialize.cc
            src/s2/third_party/absl/base/dynamic_annotations.cc
            src/s2/third_party/absl/base/internal/raw_logging.cc
            src/s2/third_party/absl/base/internal/throw_delegate.cc
            src/s2/third_party/absl/numeric/int128.cc
            src/s2/third_party/absl/strings/ascii.cc
            src/s2/third_party/absl/strings/match.cc
            src/s2/third_party/absl/strings/numbers.cc
            src/s2/third_party/absl/strings/str_cat.cc
            src/s2/third_party/absl/strings/str_split.cc
            src/s2/third_party/absl/strings/string_view.cc
            src/s2/third_party/absl/strings/strip.cc
            src/s2/third_party/absl/strings/internal/memutil.cc
            src/s2/util/bits/bit-interleave.cc
            src/s2/util/bits/bits.cc
            src/s2/util/coding/coder.cc
            src/s2/util/coding/varint.cc
            src/s2/util/math/exactfloat/exactfloat.cc
            src/s2/util/math/mathutil.cc
            src/s2/util/units/length-units.cc)

target_link_libraries(
    s2
    ${OPENSSL_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT})

# Allow other CMake projects to use this one with:
# list(APPEND CMAKE_MODULE_PATH "<path_to_s2geometry_dir>/third_party/cmake")
# add_subdirectory(<path_to_s2geometry_dir> s2geometry)
# target_link_libraries(<target_name> s2)
target_include_directories(s2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
